#include "TransfigurationSpawnController.h"

UTransfigurationSpawnController::UTransfigurationSpawnController() {
}

void UTransfigurationSpawnController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool UTransfigurationSpawnController::IsTickable() const
{
	return false;
}

TStatId UTransfigurationSpawnController::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UTransfigurationSpawnController, STATGROUP_Tickables);
}