/*
 *	server/zone/objects/guild/GuildObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "GuildObject.h"

#include "server/chat/room/ChatRoom.h"

#include "server/zone/objects/tangible/terminal/guild/GuildTerminal.h"

#include "server/zone/objects/player/PlayerCreature.h"

/*
 *	GuildObjectStub
 */

GuildObject::GuildObject() : SceneObject(DummyConstructorParameter::instance()) {
	GuildObjectImplementation* _implementation = new GuildObjectImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

GuildObject::GuildObject(DummyConstructorParameter* param) : SceneObject(param) {
}

GuildObject::~GuildObject() {
}


void GuildObject::sendBaselinesTo(SceneObject* player) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendBaselinesTo(player);
}

void GuildObject::broadcastMessage(BaseMessage* msg) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(msg);

		method.executeWithVoidReturn();
	} else
		_implementation->broadcastMessage(msg);
}

void GuildObject::broadcastMessage(PlayerCreature* player, BaseMessage* msg, bool sendSelf) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);
		method.addObjectParameter(msg);
		method.addBooleanParameter(sendSelf);

		method.executeWithVoidReturn();
	} else
		_implementation->broadcastMessage(player, msg, sendSelf);
}

void GuildObject::addMember(unsigned long long playerID) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addUnsignedLongParameter(playerID);

		method.executeWithVoidReturn();
	} else
		_implementation->addMember(playerID);
}

void GuildObject::removeMember(unsigned long long playerID) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addUnsignedLongParameter(playerID);

		method.executeWithVoidReturn();
	} else
		_implementation->removeMember(playerID);
}

bool GuildObject::hasMember(unsigned long long playerID) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addUnsignedLongParameter(playerID);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->hasMember(playerID);
}

GuildMemberInfo* GuildObject::getMember(unsigned long long playerID) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getMember(playerID);
}

void GuildObject::addSponsoredPlayer(unsigned long long playerID) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addUnsignedLongParameter(playerID);

		method.executeWithVoidReturn();
	} else
		_implementation->addSponsoredPlayer(playerID);
}

void GuildObject::removeSponsoredPlayer(unsigned long long playerID) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addUnsignedLongParameter(playerID);

		method.executeWithVoidReturn();
	} else
		_implementation->removeSponsoredPlayer(playerID);
}

bool GuildObject::hasSponsoredPlayer(unsigned long long playerID) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addUnsignedLongParameter(playerID);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->hasSponsoredPlayer(playerID);
}

unsigned long long GuildObject::getSponsoredPlayer(int idx) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addSignedIntParameter(idx);

		return method.executeWithUnsignedLongReturn();
	} else
		return _implementation->getSponsoredPlayer(idx);
}

int GuildObject::getSponsoredPlayerCount() {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getSponsoredPlayerCount();
}

void GuildObject::startChatRoom() {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		method.executeWithVoidReturn();
	} else
		_implementation->startChatRoom();
}

void GuildObject::destroyChatRoom() {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);

		method.executeWithVoidReturn();
	} else
		_implementation->destroyChatRoom();
}

ChatRoom* GuildObject::getChatRoom() {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);

		return (ChatRoom*) method.executeWithObjectReturn();
	} else
		return _implementation->getChatRoom();
}

int GuildObject::getTotalMembers() {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getTotalMembers();
}

unsigned long long GuildObject::getGuildLeaderID() {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);

		return method.executeWithUnsignedLongReturn();
	} else
		return _implementation->getGuildLeaderID();
}

GuildMemberList* GuildObject::getGuildMemberList() {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getGuildMemberList();
}

String GuildObject::getGuildAbbrev() {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);

		method.executeWithAsciiReturn(_return_getGuildAbbrev);
		return _return_getGuildAbbrev;
	} else
		return _implementation->getGuildAbbrev();
}

void GuildObject::setGuildAbbrev(const String& abbrev) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);
		method.addAsciiParameter(abbrev);

		method.executeWithVoidReturn();
	} else
		_implementation->setGuildAbbrev(abbrev);
}

void GuildObject::setGuildLeaderID(unsigned long long leaderID) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);
		method.addUnsignedLongParameter(leaderID);

		method.executeWithVoidReturn();
	} else
		_implementation->setGuildLeaderID(leaderID);
}

void GuildObject::setGuildID(unsigned int id) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);
		method.addUnsignedIntParameter(id);

		method.executeWithVoidReturn();
	} else
		_implementation->setGuildID(id);
}

unsigned int GuildObject::getGuildID() {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 26);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->getGuildID();
}

void GuildObject::setGuildName(const String& gname) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 27);
		method.addAsciiParameter(gname);

		method.executeWithVoidReturn();
	} else
		_implementation->setGuildName(gname);
}

String GuildObject::getGuildName() {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 28);

		method.executeWithAsciiReturn(_return_getGuildName);
		return _return_getGuildName;
	} else
		return _implementation->getGuildName();
}

String GuildObject::getGuildKey() {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 29);

		method.executeWithAsciiReturn(_return_getGuildKey);
		return _return_getGuildKey;
	} else
		return _implementation->getGuildKey();
}

bool GuildObject::isGuildObject() {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 30);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isGuildObject();
}

bool GuildObject::hasMailPermission(unsigned long long playerID) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 31);
		method.addUnsignedLongParameter(playerID);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->hasMailPermission(playerID);
}

bool GuildObject::hasSponsorPermission(unsigned long long playerID) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 32);
		method.addUnsignedLongParameter(playerID);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->hasSponsorPermission(playerID);
}

bool GuildObject::hasAcceptPermission(unsigned long long playerID) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 33);
		method.addUnsignedLongParameter(playerID);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->hasAcceptPermission(playerID);
}

bool GuildObject::hasDisbandPermission(unsigned long long playerID) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 34);
		method.addUnsignedLongParameter(playerID);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->hasDisbandPermission(playerID);
}

bool GuildObject::hasKickPermission(unsigned long long playerID) {
	GuildObjectImplementation* _implementation = (GuildObjectImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 35);
		method.addUnsignedLongParameter(playerID);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->hasKickPermission(playerID);
}

DistributedObjectServant* GuildObject::_getImplementation() {

	_updated = true;
	return _impl;
}

void GuildObject::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;}

/*
 *	GuildObjectImplementation
 */

GuildObjectImplementation::GuildObjectImplementation(DummyConstructorParameter* param) : SceneObjectImplementation(param) {
	_initializeImplementation();
}


GuildObjectImplementation::~GuildObjectImplementation() {
}


void GuildObjectImplementation::finalize() {
}

void GuildObjectImplementation::_initializeImplementation() {
	_setClassHelper(GuildObjectHelper::instance());

	_serializationHelperMethod();
}

void GuildObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (GuildObject*) stub;
	SceneObjectImplementation::_setStub(stub);
}

DistributedObjectStub* GuildObjectImplementation::_getStub() {
	return _this;
}

GuildObjectImplementation::operator const GuildObject*() {
	return _this;
}

void GuildObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void GuildObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void GuildObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void GuildObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void GuildObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void GuildObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void GuildObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void GuildObjectImplementation::_serializationHelperMethod() {
	SceneObjectImplementation::_serializationHelperMethod();

	_setClassName("GuildObject");

	addSerializableVariable("chatRoom", &chatRoom);
	addSerializableVariable("guildMembers", &guildMembers);
	addSerializableVariable("sponsoredPlayers", &sponsoredPlayers);
	addSerializableVariable("guildID", &guildID);
	addSerializableVariable("guildName", &guildName);
	addSerializableVariable("guildAbbrev", &guildAbbrev);
	addSerializableVariable("guildLeaderID", &guildLeaderID);
}

GuildObjectImplementation::GuildObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/guild/GuildObject.idl(83):  		Logger.setLoggingName("GuildObject");
	Logger::setLoggingName("GuildObject");
	// server/zone/objects/guild/GuildObject.idl(85):  		guildLeaderID = 0;
	guildLeaderID = 0;
	// server/zone/objects/guild/GuildObject.idl(86):  		guildID = 0;
	guildID = 0;
	// server/zone/objects/guild/GuildObject.idl(87):  		chatRoom = null;
	chatRoom = NULL;
	// server/zone/objects/guild/GuildObject.idl(89):  		sponsoredPlayers.setNoDuplicateInsertPlan();
	(&sponsoredPlayers)->setNoDuplicateInsertPlan();
	// server/zone/objects/guild/GuildObject.idl(90):  		guildMembers.setNoDuplicateInsertPlan();
	(&guildMembers)->setNoDuplicateInsertPlan();
}

void GuildObjectImplementation::addSponsoredPlayer(unsigned long long playerID) {
	Locker _locker(_this);
	// server/zone/objects/guild/GuildObject.idl(110):  		sponsoredPlayers.put(playerID);
	(&sponsoredPlayers)->put(playerID);
}

void GuildObjectImplementation::removeSponsoredPlayer(unsigned long long playerID) {
	Locker _locker(_this);
	// server/zone/objects/guild/GuildObject.idl(114):  		sponsoredPlayers.drop(playerID);
	(&sponsoredPlayers)->drop(playerID);
}

bool GuildObjectImplementation::hasSponsoredPlayer(unsigned long long playerID) {
	Locker _locker(_this);
	// server/zone/objects/guild/GuildObject.idl(118):  		return sponsoredPlayers.contains(playerID);
	return (&sponsoredPlayers)->contains(playerID);
}

unsigned long long GuildObjectImplementation::getSponsoredPlayer(int idx) {
	Locker _locker(_this);
	// server/zone/objects/guild/GuildObject.idl(122):  		return sponsoredPlayers.get(idx);
	return (&sponsoredPlayers)->get(idx);
}

int GuildObjectImplementation::getSponsoredPlayerCount() {
	// server/zone/objects/guild/GuildObject.idl(126):  		return sponsoredPlayers.size();
	return (&sponsoredPlayers)->size();
}

ChatRoom* GuildObjectImplementation::getChatRoom() {
	// server/zone/objects/guild/GuildObject.idl(133):  		return chatRoom;
	return chatRoom;
}

int GuildObjectImplementation::getTotalMembers() {
	// server/zone/objects/guild/GuildObject.idl(137):  		return guildMembers.size();
	return (&guildMembers)->size();
}

unsigned long long GuildObjectImplementation::getGuildLeaderID() {
	// server/zone/objects/guild/GuildObject.idl(141):  		return guildLeaderID;
	return guildLeaderID;
}

GuildMemberList* GuildObjectImplementation::getGuildMemberList() {
	// server/zone/objects/guild/GuildObject.idl(146):  		return guildMembers;
	return (&guildMembers);
}

String GuildObjectImplementation::getGuildAbbrev() {
	// server/zone/objects/guild/GuildObject.idl(150):  		return guildAbbrev;
	return guildAbbrev;
}

void GuildObjectImplementation::setGuildAbbrev(const String& abbrev) {
	// server/zone/objects/guild/GuildObject.idl(154):  		guildAbbrev = abbrev;
	guildAbbrev = abbrev;
}

void GuildObjectImplementation::setGuildLeaderID(unsigned long long leaderID) {
	// server/zone/objects/guild/GuildObject.idl(158):  		guildLeaderID = leaderID;
	guildLeaderID = leaderID;
}

void GuildObjectImplementation::setGuildID(unsigned int id) {
	// server/zone/objects/guild/GuildObject.idl(162):  		guildID = id;
	guildID = id;
}

unsigned int GuildObjectImplementation::getGuildID() {
	// server/zone/objects/guild/GuildObject.idl(166):  		return guildID;
	return guildID;
}

void GuildObjectImplementation::setGuildName(const String& gname) {
	// server/zone/objects/guild/GuildObject.idl(170):  		guildName = gname;
	guildName = gname;
}

String GuildObjectImplementation::getGuildName() {
	// server/zone/objects/guild/GuildObject.idl(174):  		return guildName;
	return guildName;
}

String GuildObjectImplementation::getGuildKey() {
	// server/zone/objects/guild/GuildObject.idl(178):  		string guildKey = String.valueOf(guildID) + ":" + guildAbbrev;
	String guildKey = String::valueOf(guildID) + ":" + guildAbbrev;
	// server/zone/objects/guild/GuildObject.idl(179):  		return guildKey;
	return guildKey;
}

bool GuildObjectImplementation::isGuildObject() {
	// server/zone/objects/guild/GuildObject.idl(183):  		return true;
	return true;
}

/*
 *	GuildObjectAdapter
 */

GuildObjectAdapter::GuildObjectAdapter(GuildObjectImplementation* obj) : SceneObjectAdapter(obj) {
}

Packet* GuildObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		sendBaselinesTo((SceneObject*) inv->getObjectParameter());
		break;
	case 7:
		broadcastMessage((BaseMessage*) inv->getObjectParameter());
		break;
	case 8:
		broadcastMessage((PlayerCreature*) inv->getObjectParameter(), (BaseMessage*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case 9:
		addMember(inv->getUnsignedLongParameter());
		break;
	case 10:
		removeMember(inv->getUnsignedLongParameter());
		break;
	case 11:
		resp->insertBoolean(hasMember(inv->getUnsignedLongParameter()));
		break;
	case 12:
		addSponsoredPlayer(inv->getUnsignedLongParameter());
		break;
	case 13:
		removeSponsoredPlayer(inv->getUnsignedLongParameter());
		break;
	case 14:
		resp->insertBoolean(hasSponsoredPlayer(inv->getUnsignedLongParameter()));
		break;
	case 15:
		resp->insertLong(getSponsoredPlayer(inv->getSignedIntParameter()));
		break;
	case 16:
		resp->insertSignedInt(getSponsoredPlayerCount());
		break;
	case 17:
		startChatRoom();
		break;
	case 18:
		destroyChatRoom();
		break;
	case 19:
		resp->insertLong(getChatRoom()->_getObjectID());
		break;
	case 20:
		resp->insertSignedInt(getTotalMembers());
		break;
	case 21:
		resp->insertLong(getGuildLeaderID());
		break;
	case 22:
		resp->insertAscii(getGuildAbbrev());
		break;
	case 23:
		setGuildAbbrev(inv->getAsciiParameter(_param0_setGuildAbbrev__String_));
		break;
	case 24:
		setGuildLeaderID(inv->getUnsignedLongParameter());
		break;
	case 25:
		setGuildID(inv->getUnsignedIntParameter());
		break;
	case 26:
		resp->insertInt(getGuildID());
		break;
	case 27:
		setGuildName(inv->getAsciiParameter(_param0_setGuildName__String_));
		break;
	case 28:
		resp->insertAscii(getGuildName());
		break;
	case 29:
		resp->insertAscii(getGuildKey());
		break;
	case 30:
		resp->insertBoolean(isGuildObject());
		break;
	case 31:
		resp->insertBoolean(hasMailPermission(inv->getUnsignedLongParameter()));
		break;
	case 32:
		resp->insertBoolean(hasSponsorPermission(inv->getUnsignedLongParameter()));
		break;
	case 33:
		resp->insertBoolean(hasAcceptPermission(inv->getUnsignedLongParameter()));
		break;
	case 34:
		resp->insertBoolean(hasDisbandPermission(inv->getUnsignedLongParameter()));
		break;
	case 35:
		resp->insertBoolean(hasKickPermission(inv->getUnsignedLongParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

void GuildObjectAdapter::sendBaselinesTo(SceneObject* player) {
	((GuildObjectImplementation*) impl)->sendBaselinesTo(player);
}

void GuildObjectAdapter::broadcastMessage(BaseMessage* msg) {
	((GuildObjectImplementation*) impl)->broadcastMessage(msg);
}

void GuildObjectAdapter::broadcastMessage(PlayerCreature* player, BaseMessage* msg, bool sendSelf) {
	((GuildObjectImplementation*) impl)->broadcastMessage(player, msg, sendSelf);
}

void GuildObjectAdapter::addMember(unsigned long long playerID) {
	((GuildObjectImplementation*) impl)->addMember(playerID);
}

void GuildObjectAdapter::removeMember(unsigned long long playerID) {
	((GuildObjectImplementation*) impl)->removeMember(playerID);
}

bool GuildObjectAdapter::hasMember(unsigned long long playerID) {
	return ((GuildObjectImplementation*) impl)->hasMember(playerID);
}

void GuildObjectAdapter::addSponsoredPlayer(unsigned long long playerID) {
	((GuildObjectImplementation*) impl)->addSponsoredPlayer(playerID);
}

void GuildObjectAdapter::removeSponsoredPlayer(unsigned long long playerID) {
	((GuildObjectImplementation*) impl)->removeSponsoredPlayer(playerID);
}

bool GuildObjectAdapter::hasSponsoredPlayer(unsigned long long playerID) {
	return ((GuildObjectImplementation*) impl)->hasSponsoredPlayer(playerID);
}

unsigned long long GuildObjectAdapter::getSponsoredPlayer(int idx) {
	return ((GuildObjectImplementation*) impl)->getSponsoredPlayer(idx);
}

int GuildObjectAdapter::getSponsoredPlayerCount() {
	return ((GuildObjectImplementation*) impl)->getSponsoredPlayerCount();
}

void GuildObjectAdapter::startChatRoom() {
	((GuildObjectImplementation*) impl)->startChatRoom();
}

void GuildObjectAdapter::destroyChatRoom() {
	((GuildObjectImplementation*) impl)->destroyChatRoom();
}

ChatRoom* GuildObjectAdapter::getChatRoom() {
	return ((GuildObjectImplementation*) impl)->getChatRoom();
}

int GuildObjectAdapter::getTotalMembers() {
	return ((GuildObjectImplementation*) impl)->getTotalMembers();
}

unsigned long long GuildObjectAdapter::getGuildLeaderID() {
	return ((GuildObjectImplementation*) impl)->getGuildLeaderID();
}

String GuildObjectAdapter::getGuildAbbrev() {
	return ((GuildObjectImplementation*) impl)->getGuildAbbrev();
}

void GuildObjectAdapter::setGuildAbbrev(const String& abbrev) {
	((GuildObjectImplementation*) impl)->setGuildAbbrev(abbrev);
}

void GuildObjectAdapter::setGuildLeaderID(unsigned long long leaderID) {
	((GuildObjectImplementation*) impl)->setGuildLeaderID(leaderID);
}

void GuildObjectAdapter::setGuildID(unsigned int id) {
	((GuildObjectImplementation*) impl)->setGuildID(id);
}

unsigned int GuildObjectAdapter::getGuildID() {
	return ((GuildObjectImplementation*) impl)->getGuildID();
}

void GuildObjectAdapter::setGuildName(const String& gname) {
	((GuildObjectImplementation*) impl)->setGuildName(gname);
}

String GuildObjectAdapter::getGuildName() {
	return ((GuildObjectImplementation*) impl)->getGuildName();
}

String GuildObjectAdapter::getGuildKey() {
	return ((GuildObjectImplementation*) impl)->getGuildKey();
}

bool GuildObjectAdapter::isGuildObject() {
	return ((GuildObjectImplementation*) impl)->isGuildObject();
}

bool GuildObjectAdapter::hasMailPermission(unsigned long long playerID) {
	return ((GuildObjectImplementation*) impl)->hasMailPermission(playerID);
}

bool GuildObjectAdapter::hasSponsorPermission(unsigned long long playerID) {
	return ((GuildObjectImplementation*) impl)->hasSponsorPermission(playerID);
}

bool GuildObjectAdapter::hasAcceptPermission(unsigned long long playerID) {
	return ((GuildObjectImplementation*) impl)->hasAcceptPermission(playerID);
}

bool GuildObjectAdapter::hasDisbandPermission(unsigned long long playerID) {
	return ((GuildObjectImplementation*) impl)->hasDisbandPermission(playerID);
}

bool GuildObjectAdapter::hasKickPermission(unsigned long long playerID) {
	return ((GuildObjectImplementation*) impl)->hasKickPermission(playerID);
}

/*
 *	GuildObjectHelper
 */

GuildObjectHelper* GuildObjectHelper::staticInitializer = GuildObjectHelper::instance();

GuildObjectHelper::GuildObjectHelper() {
	className = "GuildObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void GuildObjectHelper::finalizeHelper() {
	GuildObjectHelper::finalize();
}

DistributedObject* GuildObjectHelper::instantiateObject() {
	return new GuildObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* GuildObjectHelper::instantiateServant() {
	return new GuildObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* GuildObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new GuildObjectAdapter((GuildObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

