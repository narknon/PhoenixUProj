#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_ClothOptions.generated.h"

UCLASS(Blueprintable)
class USceneActionState_ClothOptions : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    USceneActionState_ClothOptions();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetPreviousAnimDriveStiffness() const;
    
};

