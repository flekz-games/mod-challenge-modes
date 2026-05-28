#ifndef AZEROTHCORE_CHALLENGEMODES_H
#define AZEROTHCORE_CHALLENGEMODES_H

#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellMgr.h"
#include "Item.h"
#include "ItemTemplate.h"
#include "GameObjectAI.h"
#include "Pet.h"
#include <map>


enum ChallengeModeSettings
{
    SETTING_HARDCORE                = 0,
    UNSETTING_HARDCORE              = 1,
    SETTING_SEMI_HARDCORE           = 2,
    UNSETTING_SEMI_HARDCORE         = 3,
    SETTING_LOSE_XP                 = 4,
    UNSETTING_LOSE_XP               = 5,
    SETTING_SELF_CRAFTED            = 6,
    UNSETTING_SELF_CRAFTED          = 7,
    SETTING_ITEM_QUALITY_LEVEL      = 8,
    UNSETTING_ITEM_QUALITY_LEVEL    = 9,
    SETTING_SLOW_XP_GAIN            = 10,
    UNSETTING_SLOW_XP_GAIN          = 11,
    SETTING_VERY_SLOW_XP_GAIN       = 12,
    UNSETTING_VERY_SLOW_XP_GAIN     = 13,
    SETTING_QUEST_XP_ONLY           = 14,
    UNSETTING_QUEST_XP_ONLY         = 15,
    SETTING_IRON_MAN                = 16,
    UNSETTING_IRON_MAN              = 17,
    HARDCORE_DEAD                   = 18
};

enum AllowedProfessions
{
    RUNEFORGING    = 53428,
    POISONS        = 2842,
    BEAST_TRAINING = 5149
};



class ChallengeModes
{
public:
    static ChallengeModes* instance();

    bool challengesEnabled, hardcoreEnable, semiHardcoreEnable, loseXPEnable, selfCraftedEnable, itemQualityLevelEnable, slowXpGainEnable, verySlowXpGainEnable, questXpOnlyEnable, ironManEnable;
    uint32 hardcoreDisableLevel, semiHardcoreDisableLevel, loseXPDisableLevel, selfCraftedDisableLevel, itemQualityLevelDisableLevel, slowXpGainDisableLevel, verySlowXpGainDisableLevel, questXpOnlyDisableLevel, ironManDisableLevel;
    uint32 hardcoreItemRewardAmount, semiHardcoreItemRewardAmount, loseXPItemRewardAmount, selfCraftedItemRewardAmount, itemQualityLevelItemRewardAmount, slowXpGainItemRewardAmount, verySlowXpGainItemRewardAmount, questXpOnlyItemRewardAmount, ironManItemRewardAmount;
    float hardcoreXpBonus, semiHardcoreXpBonus, loseXPXpBonus, selfCraftedXpBonus, itemQualityLevelXpBonus, questXpOnlyXpBonus, slowXpGainBonus, verySlowXpGainBonus, ironManXpBonus;
    float loseXPPercentage;
    std::unordered_map<uint8, uint32> hardcoreTitleRewards, semiHardcoreTitleRewards, loseXPTitleRewards, selfCraftedTitleRewards, itemQualityLevelTitleRewards, slowXpGainTitleRewards, verySlowXpGainTitleRewards, questXpOnlyTitleRewards, ironManTitleRewards;
    std::unordered_map<uint8, uint32> hardcoreItemRewards, semiHardcoreItemRewards, loseXPItemRewards, selfCraftedItemRewards, itemQualityLevelItemRewards, slowXpGainItemRewards, verySlowXpGainItemRewards, questXpOnlyItemRewards, ironManItemRewards;
    std::unordered_map<uint8, uint32> hardcoreTalentRewards, semiHardcoreTalentRewards, loseXPTalentRewards, selfCraftedTalentRewards, itemQualityLevelTalentRewards, slowXpGainTalentRewards, verySlowXpGainTalentRewards, questXpOnlyTalentRewards, ironManTalentRewards;
    std::unordered_map<uint8, uint32> hardcoreAchievementReward, semiHardcoreAchievementReward, loseXPAchievementReward, selfCraftedAchievementReward, itemQualityLevelAchievementReward, slowXpGainAchievementReward, verySlowXpGainAchievementReward, questXpOnlyAchievementReward, ironManAchievementReward;

    std::unordered_map<std::string, std::unordered_map<uint8, uint32>*> rewardConfigMap =
            {
                    { "Hardcore.TitleRewards",                &hardcoreTitleRewards                 },
                    { "SemiHardcore.TitleRewards",            &semiHardcoreTitleRewards             },
                    { "LoseXP.TitleRewards",                  &loseXPTitleRewards                   },
                    { "SelfCrafted.TitleRewards",             &selfCraftedTitleRewards              },
                    { "ItemQualityLevel.TitleRewards",        &itemQualityLevelTitleRewards         },
                    { "SlowXpGain.TitleRewards",              &slowXpGainTitleRewards               },
                    { "VerySlowXpGain.TitleRewards",          &verySlowXpGainTitleRewards           },
                    { "QuestXpOnly.TitleRewards",             &questXpOnlyTitleRewards              },
                    { "IronMan.TitleRewards",                 &ironManTitleRewards                  },

                    { "Hardcore.TalentRewards",               &hardcoreTalentRewards                },
                    { "SemiHardcore.TalentRewards",           &semiHardcoreTalentRewards            },
                    { "LoseXP.TalentRewards",                 &loseXPTalentRewards                  },
                    { "SelfCrafted.TalentRewards",            &selfCraftedTalentRewards             },
                    { "ItemQualityLevel.TalentRewards",       &itemQualityLevelTalentRewards        },
                    { "SlowXpGain.TalentRewards",             &slowXpGainTalentRewards              },
                    { "VerySlowXpGain.TalentRewards",         &verySlowXpGainTalentRewards          },
                    { "QuestXpOnly.TalentRewards",            &questXpOnlyTalentRewards             },
                    { "IronMan.TalentRewards",                &ironManTalentRewards                 },

                    { "Hardcore.ItemRewards",                 &hardcoreItemRewards                  },
                    { "SemiHardcore.ItemRewards",             &semiHardcoreItemRewards              },
                    { "LoseXP.ItemRewards",                   &loseXPItemRewards                    },
                    { "SelfCrafted.ItemRewards",              &selfCraftedItemRewards               }, 
                    { "ItemQualityLevel.ItemRewards",         &itemQualityLevelItemRewards          },
                    { "SlowXpGain.ItemRewards",               &slowXpGainItemRewards                },
                    { "VerySlowXpGain.ItemRewards",           &verySlowXpGainItemRewards            },
                    { "QuestXpOnly.ItemRewards",              &questXpOnlyItemRewards               },
                    { "IronMan.ItemRewards",                  &ironManItemRewards                   },

                    { "Hardcore.AchievementReward",           &hardcoreAchievementReward            },
                    { "SemiHardcore.AchievementReward",       &semiHardcoreAchievementReward        },
                    { "LoseXP.AchievementReward",             &loseXPAchievementReward              },
                    { "SelfCrafted.AchievementReward",        &selfCraftedAchievementReward         },
                    { "ItemQualityLevel.AchievementReward",   &itemQualityLevelAchievementReward    },
                    { "SlowXpGain.AchievementReward",         &slowXpGainAchievementReward          },
                    { "VerySlowXpGain.AchievementReward",     &verySlowXpGainAchievementReward      },
                    { "QuestXpOnly.AchievementReward",        &questXpOnlyAchievementReward         },
                    { "IronMan.AchievementReward",            &ironManAchievementReward             }
            };

    [[nodiscard]] bool enabled() const { return challengesEnabled; }
    [[nodiscard]] bool challengeEnabled(ChallengeModeSettings setting) const;
    [[nodiscard]] uint32 getDisableLevel(ChallengeModeSettings setting) const;
    [[nodiscard]] float getXpBonusForChallenge(ChallengeModeSettings setting) const;
    bool challengeEnabledForPlayer(ChallengeModeSettings setting, Player* player) const;
    [[nodiscard]] const std::unordered_map<uint8, uint32> *getTitleMapForChallenge(ChallengeModeSettings setting) const;
    [[nodiscard]] const std::unordered_map<uint8, uint32> *getTalentMapForChallenge(ChallengeModeSettings setting) const;
    [[nodiscard]] const std::unordered_map<uint8, uint32> *getItemMapForChallenge(ChallengeModeSettings setting) const;
    [[nodiscard]] const std::unordered_map<uint8, uint32> *getAchievementMapForChallenge(ChallengeModeSettings setting) const;
    [[nodiscard]] uint32 getItemRewardAmount(ChallengeModeSettings setting) const;
};

#define sChallengeModes ChallengeModes::instance()

#endif //AZEROTHCORE_CHALLENGEMODES_H
