#pragma once
#include "CoreMinimal.h"
#include "CameraStackBehaviorBlend.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "CameraStackBehaviorJumpLag.generated.h"

class AAmbulatory_Character;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCameraStackBehaviorJumpLag : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UCameraStackBehaviorJumpLag();
protected:
    UFUNCTION(BlueprintCallable)
    void OnTeleport(AAmbulatory_Character* Character, FVector AmountDisplaced, FRotator AmountRotated);
    
};

