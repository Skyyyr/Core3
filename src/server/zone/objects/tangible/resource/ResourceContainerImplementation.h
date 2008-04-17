/*
Copyright (C) 2007 <SWGEmu>
 
This File is part of Core3.
 
This program is free software; you can redistribute 
it and/or modify it under the terms of the GNU Lesser 
General Public License as published by the Free Software
Foundation; either version 2 of the License, 
or (at your option) any later version.
 
This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
See the GNU Lesser General Public License for
more details.
 
You should have received a copy of the GNU Lesser General 
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 
Linking Engine3 statically or dynamically with other modules 
is making a combined work based on Engine3. 
Thus, the terms and conditions of the GNU Lesser General Public License 
cover the whole combination.
 
In addition, as a special exception, the copyright holders of Engine3 
give you permission to combine Engine3 program with free software 
programs or libraries that are released under the GNU LGPL and with 
code included in the standard release of Core3 under the GNU LGPL 
license (or modified versions of such code, with unchanged license). 
You may copy and distribute such a system following the terms of the 
GNU LGPL for Engine3 and the licenses of the other code concerned, 
provided that you include the source code of that other code when 
and as the GNU LGPL requires distribution of source code.
 
Note that people who make modified versions of Engine3 are not obligated 
to grant this special exception for their modified versions; 
it is their choice whether to do so. The GNU Lesser General Public License 
gives permission to release a modified version without this exception; 
this exception also makes it possible to release a modified version 
which carries forward this exception.
*/

#ifndef RESOURCECONTAINERIMPLEMENTATION_H_
#define RESOURCECONTAINERIMPLEMENTATION_H_

#include "../../player/Player.h"

#include "../../../Zone.h"
#include "../../../ZoneClient.h"

#include "../../../managers/resource/ResourceManager.h"
#include "../../../managers/item/ItemManager.h"

#include "ResourceContainer.h"

class ResourceContainerImplementation : public ResourceContainerServant {
private:
	int quantity;
	int res_dr;
	int res_oq;
	int res_fl;
	int res_pe;
	int res_m;
	int res_t;
	int res_sr;
	int res_cr;
	int res_hr;
	int res_c;
	int res_er;
	string res_class7;
	string res_name;
	
	uint64 resourceID;
	
public:
	static const int MAXQUANTITY = 100000;
	
	ResourceContainerImplementation(uint64 oid);
	ResourceContainerImplementation(uint64 objectid, uint32 tempCRC, const unicode& n, const string& tempn);
	ResourceContainerImplementation(CreatureObject* creature, uint32 tempCRC, const unicode& n, const string& tempn);
	
	~ResourceContainerImplementation();
	
	void init();
	
	void sendTo(Player* player, bool doClose = true);
	void sendDeltas(Player* player);
	void generateAttributes(SceneObject* obj);
	
	void splitContainer(Player* player, int newQuantity);
	void transferContents(Player* player, ResourceContainer* fromRCO);
	
	void parseItemAttributes();
	
	void addAttributes(AttributeListMessage* alm);
	
	inline void setContents(int i) {
		quantity = i;
		string temp = "quantity";
		itemAttributes->setIntAttribute(temp, i);
	}
	
	inline void setDecayResistance(int i) {
		res_dr = i;
		string temp = "res_dr";
		itemAttributes->setIntAttribute(temp, i);
	}
	
	inline void setQuality(int i) { 
		res_oq = i;
		string temp = "res_oq";
		itemAttributes->setIntAttribute(temp, i);
	}

	inline void setFlavor(int i) {
		res_fl = i;
		string temp = "res_fl";
		itemAttributes->setIntAttribute(temp, i);
	}

	inline void setPotentialEnergy(int i) {
		res_pe = i;
		string temp = "res_pe";
		itemAttributes->setIntAttribute(temp, i);
	}
	
	inline void setMalleability(int i) {
		res_m = i;
		string temp = "res_m";
		itemAttributes->setIntAttribute(temp, i);
	}

	inline void setToughness(int i) {
		res_t = i;
		string temp = "res_t";
		itemAttributes->setIntAttribute(temp, i);
	}

	inline void setShockResistance(int i) {
		res_sr = i;
		string temp = "res_sr";
		itemAttributes->setIntAttribute(temp, i);
	}

	inline void setColdResistance(int i) {
		res_cr = i;
		string temp = "res_cr";
		itemAttributes->setIntAttribute(temp, i);
	}

	inline void setHeatResistance(int i) {
		res_hr = i;
		string temp = "res_hr";
		itemAttributes->setIntAttribute(temp, i);
	}

	inline void setConductivity(int i) {
		res_c = i;
		string temp = "res_c";
		itemAttributes->setIntAttribute(temp, i);
	}
	
	inline void setEntangleResistance(int i) {
		res_er = i;
		string temp = "res_er";
		itemAttributes->setIntAttribute(temp, i);
	}
	
	inline void setClassSeven(string& str) {
		res_class7 = str;
		string temp = "res_class7";
		itemAttributes->setStringAttribute(temp, str);
	}
	
	inline void setResourceName(string& str) {
		res_name = str;
		string temp = "res_name";
		itemAttributes->setStringAttribute(temp, str);
	}
	
	inline void setResourceID(uint64 rid) {
		resourceID = rid;
		string temp = "resourceID";
		itemAttributes->setUnsignedLongAttribute(temp, resourceID);
	}
	
	inline void setName(unicode& n) {
		name = unicode(n.c_str());
	}
	
	inline void setContainerFile(string& tempn) {
		templateName = tempn;
	}
	
	inline void setObjectCRC(uint32 tempCRC) {
		objectCRC = tempCRC;
	}
	
	inline void setObjectSubType(int subType) {
		objectSubType = subType;
	}
	
	inline int getContents() {
		return quantity;
	}
	
	inline int getMaxContents() {
		return MAXQUANTITY;
	}
	
	inline int getDecayResistance() {
		return res_dr;
	}
	
	inline int getQuality() {
		return res_oq;
	}

	inline int getFlavor() {
		return res_fl;
	}

	inline int getPotentialEnergy() {
		return res_pe;
	}
	
	inline int getMalleability() {
		return res_m;
	}

	inline int getToughness() {
		return res_t;
	}

	inline int getShockResistance() {
		return res_sr;
	}

	inline int getColdResistance() {
		return res_cr;
	}

	inline int getHeatResistance() {
		return res_hr;
	}

	inline int getConductivity() {
		return res_c;
	}
	
	inline int getEntangleResistance() {
		return res_er;
	}
	
	inline string& getClassSeven() {
		return res_class7;
	}
	
	inline string& getResourceName() {
		return res_name;
	}
	
	inline uint64 getResourceID() {
		return resourceID;
	}
};

#endif /*RESOURCECONTAINERIMPLEMENTATION_H_*/
