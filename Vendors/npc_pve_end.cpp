/*
<--------------------------------------------------------------------------->
- Developer(s): InfusionWoW
- Updated By: Ghostcrawler336
- Complete: %0
- ScriptName: 'npc_pve_end'
- Comment: N/A
<--------------------------------------------------------------------------->
*/
class multi_pve_end : public CreatureScript
{
	public:
		multi_pve_end() : CreatureScript("multi_pve_end")
		{
		}

		bool OnGossipHello(Player * pPlayer, Creature * pCreature)
		{
			Creature * npc_next = pPlayer->FindNearestCreature(600010, 30.0f, true);
			
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Chest_Plate_RaidWarrior_I_01:24|t|r Tier 10.5", GOSSIP_SENDER_MAIN, 0);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_CHEST_PLATE_25:24|t|r Tier 10.5 Heroic", GOSSIP_SENDER_MAIN, 1);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_Bracer_36A:24|t|r Offsets", GOSSIP_SENDER_MAIN, 2);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_JEWELRY_NECKLACE_15:24|t|r Accessories", GOSSIP_SENDER_MAIN, 3);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\INV_SWORD_107:24|t|r Weapons T1", GOSSIP_SENDER_MAIN, 4);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\Mace_2H_Blacksmithing_D_04_icon:24|t|r Weapons T2", GOSSIP_SENDER_MAIN, 5);
			pPlayer->ADD_GOSSIP_ITEM(4, "|cff00ff00|TInterface\\icons\\spell_magic_lesserinvisibilty:24|t|r Nevermind", GOSSIP_SENDER_MAIN, 6);
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
						m_session->SendListInventory(Creature->GetGUID(), 2500050);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 1:
					{

						m_session->SendListInventory(Creature->GetGUID(), 2500051);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 2:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500052);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 3:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500053);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 4:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500054);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 5:
					{
						m_session->SendListInventory(Creature->GetGUID(), 2500055);
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
				case 6:
					{
						Player->PlayerTalkClass->SendCloseGossip();
					}break;
			}
			return true;
		}

};

void AddSC_multi_pve_end()
{
	new multi_pve_end();
}