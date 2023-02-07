#include "AblAbilityBlueprintLibrary.h"
#include "Templates/SubclassOf.h"

class AActor;
class UAblAbility;
class UAblAbilityComponent;
class UAblAbilityContext;
class UAblCustomTaskScratchPad;

bool UAblAbilityBlueprintLibrary::SetDrawCollisionQueries(bool Enable) {
    return false;
}

bool UAblAbilityBlueprintLibrary::IsSuccessfulStartResult(EAblAbilityStartResult Result) {
    return false;
}

bool UAblAbilityBlueprintLibrary::GetDrawCollisionQueries() {
    return false;
}

UAblAbility* UAblAbilityBlueprintLibrary::GetAbilityObjectFromClass(UClass* Class) {
    return NULL;
}

UAblCustomTaskScratchPad* UAblAbilityBlueprintLibrary::CreateCustomScratchPad(UAblAbilityContext* Context, TSubclassOf<UAblCustomTaskScratchPad> ScratchPadClass) {
    return NULL;
}

UAblAbilityContext* UAblAbilityBlueprintLibrary::CreateAbilityContext(const UAblAbility* Ability, UAblAbilityComponent* AbilityComponent, AActor* Owner, AActor* Instigator) {
    return NULL;
}

EAblAbilityStartResult UAblAbilityBlueprintLibrary::ActivateAbility(UAblAbilityContext* Context) {
    return EAblAbilityStartResult::InvalidTarget;
}

UAblAbilityBlueprintLibrary::UAblAbilityBlueprintLibrary() {
}

