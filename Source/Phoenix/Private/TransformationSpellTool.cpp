#include "TransformationSpellTool.h"

class AActor;
class ATransfigurationPlaceholder;

void ATransformationSpellTool::TransformPlaceholder_Implementation(ATransfigurationPlaceholder* Placeholder, AActor* ExistingActor, FVector FxInfoCenter, FVector FxInfoExtent) {
}

void ATransformationSpellTool::StartHoldTransforming() {
}

void ATransformationSpellTool::SpawnPlaceholderNow(ATransfigurationPlaceholder* Placeholder) {
}

void ATransformationSpellTool::OnPreviewDestroyed(AActor* DestroyedActor) {
}

void ATransformationSpellTool::FinishHoldTransforming() {
}

void ATransformationSpellTool::ExitTransformAll() {
}

void ATransformationSpellTool::EnterTransformAll() {
}

void ATransformationSpellTool::CancelHoldTransforming() {
}

ATransformationSpellTool::ATransformationSpellTool() {
    this->LeftBehindPreviewActor = NULL;
    this->TransformationDuration = 1.00f;
}

