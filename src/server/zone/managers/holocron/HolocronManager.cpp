/*
 * HolocronManager.cpp
 *
 *  Created on: Nov 22, 2010
 *      Author: crush
 */

#include "HolocronManager.h"
#include "server/zone/ZoneClientSession.h"
#include "server/zone/packets/ui/CreateTicketResponseMessage.h"
#include "server/zone/packets/ui/RequestCategoriesResponseMessage.h"
#include "server/db/MantisDatabase.h"
#include "server/login/account/Account.h"
#include "BugCategory.h"

void HolocronManager::loadBugCategories() {
	String query = "SELECT `category` FROM `" + MantisDatabase::getTablePrefix() + "project_category_table` WHERE project_id = 1;";

	ResultSet* result = NULL;

	try {
		result = MantisDatabase::instance()->executeQuery(query);

		while (result->next()) {
			UnicodeString categoryName = result->getString(0);
			BugCategory category(categoryName, 0); //Category Id is also irrelevant to Mantis.
			category.addCategory(BugCategory("None", 0, 1, 1)); //Mantis doesn't allow sub categories. Kill it here.
			categories.put(category);
		}

		info("Loaded " + String::valueOf(categories.size()) + " categories from Mantis.", true);

	} catch (DatabaseException& e) {
		info(e.getMessage(), true);
	}

	if (result != NULL) {
		delete result;
		result = NULL;
	}
}

void HolocronManager::sendRequestCategoriesResponseTo(ZoneClientSession* client) {
	RequestCategoriesResponseMessage* rcrm = new RequestCategoriesResponseMessage(&categories);
	client->sendMessage(rcrm);
}

void HolocronManager::submitTicket(ZoneClientSession* client, const UnicodeString& ticketBody) {

	String sanitizedBody(ticketBody.toString());
	Database::escapeString(sanitizedBody);

	String summary = "Submitted from in-game bug reporting tool.";

	StringBuffer query;
	query << "INSERT INTO `" << MantisDatabase::getTablePrefix() << "bug_text_table` (`description`, `steps_to_reproduce`, `additional_information`) VALUES ('" << sanitizedBody << "', '', '" << summary << "');";

	ResultSet* result = NULL;

	try {
		result = MantisDatabase::instance()->executeQuery(query.toString());

		uint32 bugTextId = (uint32) result->getLastAffectedRow();
		uint32 reporterId = getReporterId(client);
		String category = getTokenValue("Bug Type: ", ticketBody);
		String severity = getTokenValue("Severity: ", ticketBody);
		String reproducibility = getTokenValue("Repeatable: ", ticketBody);

		uint32 sev = 50; //TODO: Determine severity based on string.
		uint32 rep = 10; //TODO: Determine reproducibility based on string.

		Database::escapeString(category);

		Time now;
		uint32 timestamp = now.getTime();

		StringBuffer insert;
		insert << "INSERT INTO " << MantisDatabase::getTablePrefix() << "bug_table (project_id, reporter_id, severity, reproducibility, category, date_submitted, last_updated, bug_text_id, summary) VALUES (";
		insert << "1, " << reporterId << ", " << sev << ", " << rep << ", '" << category << "', FROM_UNIXTIME(" << timestamp << "), FROM_UNIXTIME(" << timestamp << "), " << bugTextId << ", '" << summary << "');";

		MantisDatabase::instance()->executeStatement(insert.toString());

	} catch (DatabaseException& e) {
		info(e.getMessage(), true);
	}

	if (result != NULL) {
		delete result;
		result = NULL;
	}

	//TODO: Find out why this is causing a crash!
	//CreateTicketResponseMessage* ctrm = new CreateTicketResponseMessage();
	//client->sendMessage(ctrm);
}

uint32 HolocronManager::getReporterId(ZoneClientSession* client) {
	ManagedReference<Account*> account = client->getAccount();

	if (account == NULL)
		return 0;

	uint32 reporterId = 0;

	StringBuffer query;
	query << "SELECT `id` FROM `" << MantisDatabase::getTablePrefix() << "user_table` WHERE `username` = '" << account->getUsername() << "' LIMIT 1;";

	ResultSet* result = NULL;

	try {
		result = MantisDatabase::instance()->executeQuery(query.toString());

		if (result->next())
			reporterId = result->getUnsignedInt(0);

	} catch (DatabaseException& e) {
		info(e.getMessage(), true);
	}

	if (result != NULL) {
		delete result;
		result = NULL;
	}

	return reporterId;
}

uint32 HolocronManager::createReporterId(ZoneClientSession* client) {
	return 0;
}

String HolocronManager::getTokenValue(const String& token, const UnicodeString& report) {
	int iidx = report.indexOf(token);
	int fidx = report.indexOf("\n", iidx);

	return report.subString(iidx + 10, fidx).toString();
}
