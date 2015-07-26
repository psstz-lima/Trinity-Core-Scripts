/*
<--------------------------------------------------------------------------->
- Developer(s): InfusionWoW
- Updated By: Ghostcrawler336
- Complete: %0
- ScriptName: 'npc_transmog_weapon'
- Comment: N/A
<--------------------------------------------------------------------------->
*/
enum arenarating 
{
        arenarating		= 0,
		arenarating1	= 1850,
		arenarating2	= 2250,
		arenarating3	= 2250,
		arenarating4	= 2250
};

class multi_transmog_weapon : public CreatureScript
{
	public:
		multi_transmog_weapon() : CreatureScript("multi_transmog_weapon")
		{
		}

		bool OnGossipHello(Player * pPlayer, Creature * pCreature)
		{
			Creature * npc_next = pPlayer->FindNearestCreature(600010, 30.0f, true);
						
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\ACHIEVEMENT_ARENA_2V2_1:24|t|r FREE - Season 1 Weapons", GOSSIP_SENDER_MAIN, 0);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_Arena_3v3_4:24|t|r 1500 - Season 2 Weapons", GOSSIP_SENDER_MAIN, 1);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_Arena_5v5_6:24|t|r 1850 - Season 3 Weapons", GOSSIP_SENDER_MAIN, 2);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Achievement_Arena_5v5_7:24|t|r 2250 - Season 4 Weapons", GOSSIP_SENDER_MAIN, 3);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\spell_magic_lesserinvisibilty:24|t|r Nevermind", GOSSIP_SENDER_MAIN, 4);
			pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
			return true;
		}

		bool OnGossipSelect(Player * Player, Creature * Creature, uint32 /*uiSender*/, uint32 uiAction)
		{
			Player->PlayerTalkClass->ClearMenus();
			if(!Player)
				return true;
			
			WorldSession * m_session = Player->GetSession();
			
			switch(uiAction)
			{
				case 0:
					if (Player->GetArenaPersonalRating(ARENA_TEAM_TYPE) >= arenarating || 
						Player->GetArenaPersonalRating(ARENA_TEAM_TYPE) >= arenarating ||
						Player->GetArenaPersonalRating(ARENA_TEAM_TYPE) >= arenarating)
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500031);
						Player->PlayerTalkClass->SendCloseGossip();
					}else
					{
						ChatHandler(Player->GetSession()).PSendSysMessage("|cffff6060[Information]:|r You need atleast |cFFFF4500%u|r 2v2 or 3v3 rating to buy this item!", arenarating);
						Player->CLOSE_GOSSIP_MENU();
                        return false;
					}break;

				case 1:
					if (Player->GetArenaPersonalRating(ARENA_TEAM_TYPE) >= arenarating1 ||
						Player->GetArenaPersonalRating(ARENA_TEAM_TYPE) >= arenarating1 ||
						Player->GetArenaPersonalRating(ARENA_TEAM_TYPE) >= arenarating1)
					{

						m_session->SendListInventory(Creature->GetGUID(), 2500031);
						Player->PlayerTalkClass->SendCloseGossip();
					}else
					{
						ChatHandler(Player->GetSession()).PSendSysMessage("|cffff6060[Information]:|r You need atleast |cFFFF4500%u|r 2v2 or 3v3 rating to buy this item!", arenarating1);
						Player->CLOSE_GOSSIP_MENU();
                        return false;
					}break;

				case 2:
					if (Player->GetArenaPersonalRating(ARENA_TEAM_TYPE) >= arenarating2 ||
						Player->GetArenaPersonalRating(ARENA_TEAM_TYPE) >= arenarating2 ||
						Player->GetArenaPersonalRating(ARENA_TEAM_TYPE) >= arenarating2)
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500031);
						Player->PlayerTalkClass->SendCloseGossip();
					}else
					{
						ChatHandler(Player->GetSession()).PSendSysMessage("|cffff6060[Information]:|r You need atleast |cFFFF4500%u|r 2v2 or 3v3 rating to buy this item!", arenarating2);
						Player->CLOSE_GOSSIP_MENU();
                        return false;
					}break;

				case 3:
					if (Player->GetArenaPersonalRating(ARENA_TEAM_TYPE) >= arenarating3 ||
						Player->GetArenaPersonalRating(ARENA_TEAM_TYPE) >= arenarating3 ||
						Player->GetArenaPersonalRating(ARENA_TEAM_TYPE) >= arenarating3)
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500031);
						Player->PlayerTalkClass->SendCloseGossip();
					}else
					{
						ChatHandler(Player->GetSession()).PSendSysMessage("|cffff6060[Information]:|r You need atleast |cFFFF4500%u|r 2v2 or 3v3 rating to buy this item!", arenarating3);
						Player->CLOSE_GOSSIP_MENU();
                        return false;
					}break;

				case 4:
					{
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 6:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500031);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 7:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500031);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 8:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500031);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 9:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500031);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
			}
			return true;
		}

};

void AddSC_multi_transmog_weapon()
{
	new multi_transmog_weapon();
}