#pragma once

#include "../HyunsoonEngine_CommonSources/Resource/ResourceManager.h"
#include "../HyunsoonEngine_CommonSources/Resource/Texture.h"

namespace hs
{
	void LoadResources()
	{
		// Background
		{
			ResourceManager::Load<graphics::Texture>(L"bg_Sky", L"../HyunsoonEngine_Window/MaplestoryResources/MapBackground/Sky3.bmp");
			// ResourceManager::Load<graphics::Texture>(L"bg_Sky", L"../HyunsoonEngine_Window/MaplestoryResources/MapBackground/Land.bmp");
			ResourceManager::Load<graphics::Texture>(L"bg_Alter", L"../HyunsoonEngine_Window/MaplestoryResources/MapBackground/AlterOfZakumBack.bmp");

			ResourceManager::Load<graphics::Texture>(L"bg_BeginnersTown1", L"../HyunsoonEngine_Window/MaplestoryResources/BeginnersTown1/BeginnersTown1NotSprite/BeginnersTown1/BeginnersTown1Background.bmp");

			ResourceManager::Load<graphics::Texture>(L"bg_BeginnersTown2", L"../HyunsoonEngine_Window/MaplestoryResources/BeginnersTown2/BeginnersTown2NotSprite/BeginnersTown2/BeginnersTown2Background.bmp");

			ResourceManager::Load<graphics::Texture>(L"bg_CrossRoad", L"../HyunsoonEngine_Window/MaplestoryResources/CrossRoad/CrossRoadNotSprite/CrossRoad/CrossRoad.bmp");

			ResourceManager::Load<graphics::Texture>(L"bg_SouthFerry", L"../HyunsoonEngine_Window/MaplestoryResources/Southferry/SouthferryNotSprite/Map/SouthFerry.bmp");

			ResourceManager::Load<graphics::Texture>(L"bg_KerningCityBack", L"../HyunsoonEngine_Window/MaplestoryResources/KerningCity/KerningCityNotSprite/Map/KerningCityBackGround.bmp");
			ResourceManager::Load<graphics::Texture>(L"bg_KerningCity", L"../HyunsoonEngine_Window/MaplestoryResources/KerningCity/KerningCityNotSprite/Map/KerningCity.bmp");

			ResourceManager::Load<graphics::Texture>(L"bg_ZakumRoad", L"../HyunsoonEngine_Window/MaplestoryResources/ZakumRoad1/ZakumRoad1NotSprite/Map/ZakumRoad.bmp");
			ResourceManager::Load<graphics::Texture>(L"bg_ZakumRoadBack", L"../HyunsoonEngine_Window/MaplestoryResources/ZakumRoad1/ZakumRoad1NotSprite/Map/ZakumRoadBackGround.bmp");

			ResourceManager::Load<graphics::Texture>(L"bg_AlterOfZakumEnt", L"../HyunsoonEngine_Window/MaplestoryResources/AlterOfZakumEnt/AlterOfZakumEntNotSprite/Map/AlterOfZakumEnt.bmp");
			ResourceManager::Load<graphics::Texture>(L"bg_AlterOfZakumEntLayer", L"../HyunsoonEngine_Window/MaplestoryResources/AlterOfZakumEnt/AlterOfZakumEntNotSprite/Map/AlterOfZakumEntLayer.bmp");
			ResourceManager::Load<graphics::Texture>(L"bg_Pillar", L"../HyunsoonEngine_Window/MaplestoryResources/AlterOfZakumEnt/AlterOfZakumEntNotSprite/Map/ZakumLandScape3.bmp");

			ResourceManager::Load<graphics::Texture>(L"bg_ZakumLandScape1", L"../HyunsoonEngine_Window/MaplestoryResources/AlterOfZakumEnt/AlterOfZakumEntNotSprite/Map/ZakumLandScape1.bmp");
			ResourceManager::Load<graphics::Texture>(L"bg_ZakumLandScape2", L"../HyunsoonEngine_Window/MaplestoryResources/AlterOfZakumEnt/AlterOfZakumEntNotSprite/Map/ZakumLandScape2.bmp");
			ResourceManager::Load<graphics::Texture>(L"bg_ZakumLandScape3", L"../HyunsoonEngine_Window/MaplestoryResources/AlterOfZakumEnt/AlterOfZakumEntNotSprite/Map/ZakumLandScape3.bmp");
			ResourceManager::Load<graphics::Texture>(L"bg_ZakumLandScape4", L"../HyunsoonEngine_Window/MaplestoryResources/AlterOfZakumEnt/AlterOfZakumEntNotSprite/Map/ZakumLandScape4.bmp");

			ResourceManager::Load<graphics::Texture>(L"bg_AlterOfZakum", L"../HyunsoonEngine_Window/MaplestoryResources/AlterOfZakum/AlterOfZakumNotSprite/Map/AlterOfZakum/AlterOfZakum.bmp");
			ResourceManager::Load<graphics::Texture>(L"bg_AlterOfZakumLayer", L"../HyunsoonEngine_Window/MaplestoryResources/AlterOfZakum/AlterOfZakumNotSprite/Map/AlterOfZakum/AlterOfZakumLayer.bmp");
		}

		// Player
		{
			ResourceManager::Load<graphics::Texture>(L"PlayerIdle_L", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Idle_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerIdle_R", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Idle_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerAlert_L", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Alert_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerAlert_R", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Alert_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerWalk_L", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Walk_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerWalk_R", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Walk_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerJump_L", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Jump_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerJump_R", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Jump_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerLyingDown_L", L"../HyunsoonEngine_Window/MaplestoryResources/Character/LyingDown_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerLyingDown_R", L"../HyunsoonEngine_Window/MaplestoryResources/Character/LyingDown_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerSwing0_L", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Swing0_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerSwing0_R", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Swing0_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerSwing1_L", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Swing1_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerSwing1_R", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Swing1_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerSwing2_L", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Swing2_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"PlayerSwing2_R", L"../HyunsoonEngine_Window/MaplestoryResources/Character/Swing2_R.bmp");
		}

		// Monster
		{
			ResourceManager::Load<graphics::Texture>(L"GreenSnailIdle_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/GreenSnail/GreenSnailIdle_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"GreenSnailIdle_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/GreenSnail/GreenSnailIdle_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"GreenSnailMove_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/GreenSnail/GreenSnailMove_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"GreenSnailMove_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/GreenSnail/GreenSnailMove_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"GreenSnailAttacked_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/GreenSnail/GreenSnailAttacked_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"GreenSnailAttacked_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/GreenSnail/GreenSnailAttacked_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"GreenSnailDeath_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/GreenSnail/GreenSnailDeath_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"GreenSnailDeath_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/GreenSnail/GreenSnailDeath_R.bmp");

			ResourceManager::Load<graphics::Texture>(L"BlueSnailIdle_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/BlueSnail/BlueSnailIdle_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"BlueSnailIdle_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/BlueSnail/BlueSnailIdle_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"BlueSnailMove_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/BlueSnail/BlueSnailMove_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"BlueSnailMove_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/BlueSnail/BlueSnailMove_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"BlueSnailAttacked_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/BlueSnail/BlueSnailAttacked_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"BlueSnailAttacked_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/BlueSnail/BlueSnailAttacked_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"BlueSnailDeath_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/BlueSnail/BlueSnailDeath_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"BlueSnailDeath_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/BlueSnail/BlueSnailDeath_R.bmp");

			ResourceManager::Load<graphics::Texture>(L"SporeIdle_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Spore/SporeIdle_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"SporeIdle_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Spore/SporeIdle_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"SporeMove_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Spore/SporeMove_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"SporeMove_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Spore/SporeMove_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"SporeAttacked_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Spore/SporeAttacked_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"SporeAttacked_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Spore/SporeAttacked_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"SporeDeath_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Spore/SporeDeath_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"SporeDeath_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Spore/SporeDeath_R.bmp");

			ResourceManager::Load<graphics::Texture>(L"OrangeMushroomIdle_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/OrangeMushroom/OrangeMushroomIdle_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"OrangeMushroomIdle_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/OrangeMushroom/OrangeMushroomIdle_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"OrangeMushroomMove_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/OrangeMushroom/OrangeMushroomMove_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"OrangeMushroomMove_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/OrangeMushroom/OrangeMushroomMove_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"OrangeMushroomAttacked_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/OrangeMushroom/OrangeMushroomAttacked_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"OrangeMushroomAttacked_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/OrangeMushroom/OrangeMushroomAttacked_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"OrangeMushroomDeath_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/OrangeMushroom/OrangeMushroomDeath_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"OrangeMushroomDeath_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/OrangeMushroom/OrangeMushroomDeath_R.bmp");

			ResourceManager::Load<graphics::Texture>(L"ZombieIdle_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zombie/ZombieIdle_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"ZombieIdle_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zombie/ZombieIdle_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"ZombieMove_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zombie/ZombieMove_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"ZombieMove_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zombie/ZombieMove_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"ZombieAttacked_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zombie/ZombieAttacked_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"ZombieAttacked_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zombie/ZombieAttacked_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"ZombieDeath_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zombie/ZombieDeath_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"ZombieDeath_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zombie/ZombieDeath_R.bmp");

			// JrBalrog
			ResourceManager::Load<graphics::Texture>(L"JrBalrogIdle_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/JrBalrog/JrBalrogIdle_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"JrBalrogIdle_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/JrBalrog/JrBalrogIdle_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"JrBalrogMove_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/JrBalrog/JrBalrogMove_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"JrBalrogMove_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/JrBalrog/JrBalrogMove_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"JrBalrogAttacked_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/JrBalrog/JrBalrogAttacked_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"JrBalrogAttacked_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/JrBalrog/JrBalrogAttacked_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"JrBalrogDeath_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/JrBalrog/JrBalrogDeath_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"JrBalrogDeath_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/JrBalrog/JrBalrogDeath_R.bmp");

			// JrBalrog Effect
			ResourceManager::Load<graphics::Texture>(L"JrBalrogAttack1_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/JrBalrog/JrBalrogAttack1_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"JrBalrogAttack1_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/JrBalrog/JrBalrogAttack1_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"JrBalrogAttack2_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/JrBalrog/JrBalrogAttack2_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"JrBalrogAttack2_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/JrBalrog/JrBalrogAttack2_R.bmp");
			ResourceManager::Load<graphics::Texture>(L"JrBalrogAttackEffect1_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/JrBalrog/JrBalrogAttackEffect1_L.png");
			ResourceManager::Load<graphics::Texture>(L"JrBalrogAttackEffect1_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/JrBalrog/JrBalrogAttackEffect1_R.png");
			ResourceManager::Load<graphics::Texture>(L"JrBalrogAttackEffect2_L", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/JrBalrog/JrBalrogAttackEffect2_L.png");
			ResourceManager::Load<graphics::Texture>(L"JrBalrogAttackEffect2_R", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/JrBalrog/JrBalrogAttackEffect2_R.png");

			//Zakum
			{
				ResourceManager::Load<graphics::Texture>(L"ZakumArm0", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zakum/Arms/ZakumArm0.bmp");
				ResourceManager::Load<graphics::Texture>(L"ZakumArm1", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zakum/Arms/ZakumArm1.bmp");
				ResourceManager::Load<graphics::Texture>(L"ZakumArm2", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zakum/Arms/ZakumArm2.bmp");
				ResourceManager::Load<graphics::Texture>(L"ZakumArm3", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zakum/Arms/ZakumArm3.bmp");
				ResourceManager::Load<graphics::Texture>(L"ZakumArm4", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zakum/Arms/ZakumArm4.bmp");
				ResourceManager::Load<graphics::Texture>(L"ZakumArm5", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zakum/Arms/ZakumArm5.bmp");
				ResourceManager::Load<graphics::Texture>(L"ZakumArm6", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zakum/Arms/ZakumArm6.bmp");
				ResourceManager::Load<graphics::Texture>(L"ZakumArm7", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zakum/Arms/ZakumArm7.bmp");

				ResourceManager::Load<graphics::Texture>(L"ZakumPhase1Idle", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zakum/Phase1/ZakumIdle.bmp");
				ResourceManager::Load<graphics::Texture>(L"ZakumPhase1Death", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zakum/Phase1/ZakumDeath.bmp");
				ResourceManager::Load<graphics::Texture>(L"ZakumPhase2Idle", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zakum/Phase2/ZakumIdle.bmp");
				ResourceManager::Load<graphics::Texture>(L"ZakumPhase2Death", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zakum/Phase2/ZakumDeath.bmp");
				ResourceManager::Load<graphics::Texture>(L"ZakumPhase3Idle", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zakum/Phase3/ZakumIdle.bmp");
				ResourceManager::Load<graphics::Texture>(L"ZakumPhase3Death", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zakum/Phase3/ZakumDeath.bmp");

				ResourceManager::Load<graphics::Texture>(L"ZakumSpawn", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zakum/Spawn/ZakumSpawn.png");

				ResourceManager::Load<graphics::Texture>(L"ZakumAttack", L"../HyunsoonEngine_Window/MaplestoryResources/Monster/Zakum/Attack/ZakumAttack.png");
			}
		}

		// Item
		{
			ResourceManager::Load<graphics::Texture>(L"Shuriken_L", L"../HyunsoonEngine_Window/MaplestoryResources/Item/Shuriken_L.bmp");
			ResourceManager::Load<graphics::Texture>(L"Shuriken_R", L"../HyunsoonEngine_Window/MaplestoryResources/Item/Shuriken_R.bmp");
		}

		// Npc
		{
			ResourceManager::Load<graphics::Texture>(L"Shanks", L"../HyunsoonEngine_Window/MaplestoryResources/Npc/Shanks.bmp");
		}

		// Portal
		{
			ResourceManager::Load<graphics::Texture>(L"Portal", L"../HyunsoonEngine_Window/MaplestoryResources/Common/CommonSprite/Portal/Portals.png");
		}

		// UI
		{
			ResourceManager::Load<graphics::Texture>(L"BottomBar", L"../HyunsoonEngine_Window/MaplestoryResources/UI/BottomBar.bmp");
		}

		// DeBuff
		{
			ResourceManager::Load<graphics::Texture>(L"CannotJump", L"../HyunsoonEngine_Window/MaplestoryResources/DeBuff/CannotJump.png");
			ResourceManager::Load<graphics::Texture>(L"AccuracyDrop", L"../HyunsoonEngine_Window/MaplestoryResources/DeBuff/AccuracyDrop.png");
			ResourceManager::Load<graphics::Texture>(L"SkillLock", L"../HyunsoonEngine_Window/MaplestoryResources/DeBuff/SkillLock.png");

		}
	}
} // namespace hs