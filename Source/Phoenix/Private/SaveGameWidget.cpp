#include "SaveGameWidget.h"

bool USaveGameWidget::SaveGameInSlot(int32 SaveSlot) {
    return false;
}



int32 USaveGameWidget::ParseSlotNumFromName(const FString& SlotName) {
    return 0;
}

void USaveGameWidget::OnSaveGameFailed() {
}

void USaveGameWidget::OnAsyncSaveCompleted() {
}

void USaveGameWidget::GetUserSavesBySlot(TArray<FSaveGameInfo>& SaveData) {
}

bool USaveGameWidget::DeleteGameFromSlot(int32 SaveSlot) {
    return false;
}

USaveGameWidget::USaveGameWidget() {
}

