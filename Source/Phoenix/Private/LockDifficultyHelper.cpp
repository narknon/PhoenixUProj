#include "LockDifficultyHelper.h"

ELockDifficulty ULockDifficultyHelper::ConvertLockLevelToLockDifficulty(EDoorLockLevel LockLevel) {
    return ELockDifficulty::Level_1;
}

EDoorLockLevel ULockDifficultyHelper::ConvertLockDifficultyToLockLevel(ELockDifficulty LockDifficulty) {
    return EDoorLockLevel::Unlocked;
}

ULockDifficultyHelper::ULockDifficultyHelper() {
}

