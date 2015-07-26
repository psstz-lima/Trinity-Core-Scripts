/*
<--------------------------------------------------------------------------->
- Developer(s): InfusionWoW
- Updated By: Ghostcrawler336
- Complete: %0
- ScriptName: 'npc_glyphs'
- Comment: N/A
<--------------------------------------------------------------------------->
*/
class multi_glyphs : public CreatureScript
{
	public:
		multi_glyphs() : CreatureScript("multi_glyphs")
		{
		}
		
		bool OnGossipHello(Player * pPlayer, Creature * pCreature)
		{
			Creature * npc_next = pPlayer->FindNearestCreature(600010, 30.0f, true);
			
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Glyph_MajorPaladin:24|t|r Warrior", GOSSIP_SENDER_MAIN, 0);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Glyph_MajorPaladin:24|t|r Paladin", GOSSIP_SENDER_MAIN, 1);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Glyph_MajorPaladin:24|t|r Hunter", GOSSIP_SENDER_MAIN, 2);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Glyph_MajorPaladin:24|t|r Rogue", GOSSIP_SENDER_MAIN, 3);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Glyph_MajorPaladin:24|t|r Priest", GOSSIP_SENDER_MAIN, 4);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Glyph_MajorPaladin:24|t|r Death Knight", GOSSIP_SENDER_MAIN, 5);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Glyph_MajorPaladin:24|t|r Shaman", GOSSIP_SENDER_MAIN, 6);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Glyph_MajorPaladin:24|t|r Mage", GOSSIP_SENDER_MAIN, 7);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Glyph_MajorPaladin:24|t|r Warlock", GOSSIP_SENDER_MAIN, 8);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Glyph_MajorPaladin:24|t|r Druid", GOSSIP_SENDER_MAIN, 9);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Misc_QuestionMark|t|r Nevermind..", GOSSIP_SENDER_MAIN, 10);
			
			pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
			return true;
		}

		bool OnGossipSelect(Player * Player, Creature * Creature, uint32 /*uiSender*/, uint32 uiAction)
		{
			if(!Player)
				return true;
			
			WorldSession * m_session = Player->GetSession();
			
			switch(uiAction)
			{
				case 0:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500001);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 1:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500002);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 2:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500003);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 3:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500004);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 4:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500005);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 5:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500006);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 6:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500007);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 7:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500008);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 8:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500009);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 9:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500010);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
			    case 10: // Close Gossips
					{
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
			}
			return true;
		}

};

void AddSC_multi_glyphs()
{
	new multi_glyphs();
}