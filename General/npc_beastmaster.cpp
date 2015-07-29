#include "Pet.h"

class BeastMaster : public CreatureScript
{
public:
	BeastMaster() : CreatureScript("BeastMaster") { }

	void CreatePet(Player *player, Creature * m_creature, uint32 entry) {

		if (player->GetPet())
		{
			player->GetSession()->SendAreaTriggerMessage("First you must dismiss your Pet!");
			player->PlayerTalkClass->SendCloseGossip();
			return;
		}

		Creature *creatureTarget = m_creature->SummonCreature(entry, player->GetPositionX(), player->GetPositionY() + 2, player->GetPositionZ(), player->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 500);
		if (!creatureTarget) return;

		Pet* pet = player->CreateTamedPetFrom(creatureTarget, 0);
		if (!pet) return;

		// kill original creature
		creatureTarget->setDeathState(JUST_DIED);
		creatureTarget->RemoveCorpse();
		creatureTarget->SetHealth(0);                       // just for nice GM-mode view

		pet->SetPower(POWER_HAPPINESS, 1048000);

		pet->SetUInt64Value(UNIT_FIELD_CREATEDBY, player->GetGUID());
		pet->SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, player->getFaction());

		// prepare visual effect for levelup
		pet->SetUInt32Value(UNIT_FIELD_LEVEL, player->getLevel() - 1);
		pet->GetMap()->AddToMap(pet->ToCreature());

		// visual effect for levelup
		pet->SetUInt32Value(UNIT_FIELD_LEVEL, player->getLevel());

		pet->GetCharmInfo()->SetPetNumber(sObjectMgr->GeneratePetNumber(), true);

		pet->UpdateAllStats();

		// caster have pet now
		player->SetMinion(pet, true);

		pet->SavePetToDB(PET_SAVE_AS_CURRENT);
		pet->InitTalentForLevel();
		player->PetSpellInitialize();

		//end
		player->PlayerTalkClass->SendCloseGossip();
		player->GetSession()->SendAreaTriggerMessage("Pet added. You might want to feed it and name it somehow");
	}


	bool OnGossipHello(Player *player, Creature * m_creature)
	{
		if (player->getClass() != CLASS_HUNTER)
		{
			player->GetSession()->SendAreaTriggerMessage("You are not a Hunter!");
			return true;
		}
		player->ADD_GOSSIP_ITEM(4, "|TInterface\\Icons\\Ability_Mount_Drake_Bronze:30:30:-18:0|tPick A Pet!", GOSSIP_SENDER_MAIN, 30);
		if (player->CanTameExoticPets())
		{
			player->ADD_GOSSIP_ITEM(4, "|TInterface\\Icons\\Achievement_Boss_Malygos_01:30:30:-18:0|tPick A Exotic Pet!", GOSSIP_SENDER_MAIN, 50);
		}
		player->ADD_GOSSIP_ITEM(2, "|TInterface\\Icons\\INV_Misc_Comb_01:30:30:-18:0|tOpen Pet Stable.", GOSSIP_SENDER_SEC_STABLEMASTER, GOSSIP_OPTION_STABLEPET);
		player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\INV_Misc_Fish_16:30:30:-18:0|tBuy Some Pet Food.", GOSSIP_SENDER_MAIN, GOSSIP_OPTION_VENDOR);
		player->ADD_GOSSIP_ITEM(0, "|TInterface\\icons\\Achievement_BG_winbyten:30:30:-18:0|tExit", GOSSIP_SENDER_MAIN, 999);
		player->SEND_GOSSIP_MENU(1, m_creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player *player, Creature * m_creature, uint32 sender, uint32 action)
	{
		player->PlayerTalkClass->ClearMenus();
		switch (action)
		{
		case 100: // Main Menu
			OnGossipHello(player, m_creature);
			break;

		case 150: // Close Gossip
			player->CLOSE_GOSSIP_MENU();
			break;

		case 30:
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Bat:30:30:-18:0|tBat", GOSSIP_SENDER_MAIN, 18);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Bear:30:30:-18:0|tBear", GOSSIP_SENDER_MAIN, 1);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Boar:30:30:-18:0|tBoar", GOSSIP_SENDER_MAIN, 2);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Cat:30:30:-18:0|tCat", GOSSIP_SENDER_MAIN, 4);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\INV_Misc_Birdbeck_01:30:30:-18:0|tCarrion Bird", GOSSIP_SENDER_MAIN, 5);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Crab:30:30:-18:0|tCrab", GOSSIP_SENDER_MAIN, 6);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Crocolisk:30:30:-18:0|tCrocolisk", GOSSIP_SENDER_MAIN, 7);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_DragonHawk:30:30:-18:0|tDragonhawk", GOSSIP_SENDER_MAIN, 17);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Gorilla:30:30:-18:0|tGorilla", GOSSIP_SENDER_MAIN, 8);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Wolf:30:30:-18:0|tHound", GOSSIP_SENDER_MAIN, 9);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Hyena:30:30:-18:0|tHyena", GOSSIP_SENDER_MAIN, 10);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Moth:30:30:-18:0|tMoth", GOSSIP_SENDER_MAIN, 11);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Owl:30:30:-18:0|tOwl", GOSSIP_SENDER_MAIN, 12);
			player->ADD_GOSSIP_ITEM(4, "|TInterface\\Icons\\Ability_Vehicle_PlayerLoaded:30:30:-18:0|t[Next Page]", GOSSIP_SENDER_MAIN, 31);
			player->ADD_GOSSIP_ITEM(2, "|TInterface\\Icons\\Achievement_BG_returnXflags_def_WSG:30:30:-18:0|t[Main Menu]", GOSSIP_SENDER_MAIN, 100);
			player->SEND_GOSSIP_MENU(1, m_creature->GetGUID());
			break;

		case 31:
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Raptor:30:30:-18:0|tRaptor", GOSSIP_SENDER_MAIN, 20);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Ravager:30:30:-18:0|tRavager", GOSSIP_SENDER_MAIN, 19);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_TallStrider:30:30:-18:0|tStrider", GOSSIP_SENDER_MAIN, 13);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Scorpid:30:30:-18:0|tScorpid", GOSSIP_SENDER_MAIN, 414);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Spider:30:30:-18:0|tSpider", GOSSIP_SENDER_MAIN, 16);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_WindSerpent:30:30:-18:0|tSerpent", GOSSIP_SENDER_MAIN, 21);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Turtle:30:30:-18:0|tTurtle", GOSSIP_SENDER_MAIN, 15);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Wasp:30:30:-18:0|tWasp", GOSSIP_SENDER_MAIN, 93);
			player->ADD_GOSSIP_ITEM(4, "|TInterface\\Icons\\Ability_Vehicle_LoadSelfCatapult:30:30:-18:0|t[Prev Page]", GOSSIP_SENDER_MAIN, 30);
			player->ADD_GOSSIP_ITEM(2, "|TInterface\\Icons\\Achievement_BG_returnXflags_def_WSG:30:30:-18:0|t[Main Menu]", GOSSIP_SENDER_MAIN, 100);
			player->SEND_GOSSIP_MENU(1, m_creature->GetGUID());
			break;

		case 50:
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Chimera:30:30:-18:0|tChimaera", GOSSIP_SENDER_MAIN, 51);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_CoreHound:30:30:-18:0|tCore Hound", GOSSIP_SENDER_MAIN, 52);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Devilsaur:30:30:-18:0|tDevilsaur", GOSSIP_SENDER_MAIN, 53);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Rhino:30:30:-18:0|tRhino", GOSSIP_SENDER_MAIN, 54);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Silithid:30:30:-18:0|tSilithid", GOSSIP_SENDER_MAIN, 55);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Worm:30:30:-18:0|tWorm", GOSSIP_SENDER_MAIN, 56);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\INV_Misc_Head_Tiger_01:30:30:-18:0|tLoque'nahak", GOSSIP_SENDER_MAIN, 57);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Wolf:30:30:-18:0|tSkoll", GOSSIP_SENDER_MAIN, 58);
			player->ADD_GOSSIP_ITEM(6, "|TInterface\\Icons\\Ability_Hunter_Pet_Cat:30:30:-18:0|tGondria", GOSSIP_SENDER_MAIN, 59);
			player->ADD_GOSSIP_ITEM(2, "|TInterface\\Icons\\Achievement_BG_returnXflags_def_WSG:30:30:-18:0|t[Main Menu]", GOSSIP_SENDER_MAIN, 100);
			player->SEND_GOSSIP_MENU(1, m_creature->GetGUID());
			break;

		case GOSSIP_OPTION_STABLEPET:
			player->GetSession()->SendStablePet(m_creature->GetGUID());
			break;

		case GOSSIP_OPTION_VENDOR:
			player->GetSession()->SendListInventory(m_creature->GetGUID());
			break;

		case 51: //chimera
			CreatePet(player, m_creature, 21879);
			break;

		case 52: //core hound
			CreatePet(player, m_creature, 21108);
			break;

		case 53: //Devilsaur
			CreatePet(player, m_creature, 20931);
			break;

		case 54: //rhino
			CreatePet(player, m_creature, 30445);
			break;

		case 55: //silithid
			CreatePet(player, m_creature, 5460);
			break;

		case 56: //Worm
			CreatePet(player, m_creature, 30148);
			break;

		case 57: //Loque'nahak
			CreatePet(player, m_creature, 32517);
			break;

		case 58: //Skoll
			CreatePet(player, m_creature, 35189);
			break;

		case 59: //Gondria
			CreatePet(player, m_creature, 33776);
			break;

		case 16: //Spider
			CreatePet(player, m_creature, 2349);
			break;

		case 17: //Dragonhawk
			CreatePet(player, m_creature, 27946);
			break;

		case 18: //Bat
			CreatePet(player, m_creature, 28233);
			break;

		case 19: //Ravager
			CreatePet(player, m_creature, 17199);
			break;

		case 20: //Raptor
			CreatePet(player, m_creature, 14821);
			break;

		case 21: //Serpent
			CreatePet(player, m_creature, 28358);
			break;

		case 1: //bear
			CreatePet(player, m_creature, 29319);
			break;

		case 2: //Boar
			CreatePet(player, m_creature, 29996);
			break;

		case 93: //Bug
			CreatePet(player, m_creature, 28085);
			break;

		case 4: //cat
			CreatePet(player, m_creature, 28097);
			break;

		case 5: //carrion
			CreatePet(player, m_creature, 26838);
			break;

		case 6: //crab
			CreatePet(player, m_creature, 24478);
			break;

		case 7: //crocolisk
			CreatePet(player, m_creature, 1417);
			break;

		case 8: //gorila
			CreatePet(player, m_creature, 28213);
			break;

		case 9: //hound
			CreatePet(player, m_creature, 29452);
			break;

		case 10: //hynea
			CreatePet(player, m_creature, 13036);
			break;

		case 11: //Moth
			CreatePet(player, m_creature, 27421);
			break;

		case 12: //owl
			CreatePet(player, m_creature, 23136);
			break;

		case 13: //strider
			CreatePet(player, m_creature, 22807);
			break;

		case 414: //scorpid
			CreatePet(player, m_creature, 9698);
			break;

		case 15: //turtle
			CreatePet(player, m_creature, 25482);
			break;

		case 999: // Exit
			player->CLOSE_GOSSIP_MENU();
			break;
		}
		return true;
	}
};

void AddSC_BeastMaster()
{
	new BeastMaster();
}