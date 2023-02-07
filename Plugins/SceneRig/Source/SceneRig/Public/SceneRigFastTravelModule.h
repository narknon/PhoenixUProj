#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EFT_TriggerType.h"
#include "SceneRigFastTravelModule.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneRigFastTravelModule : public UObject {
    GENERATED_BODY()
public:
    USceneRigFastTravelModule();
    UFUNCTION(BlueprintCallable)
    static void SetFastTravelTriggerName(const FString& TriggerName, EFT_TriggerType TriggerType);
    
    UFUNCTION(BlueprintCallable)
    static FString GetFastTravelTriggerName(EFT_TriggerType TriggerType);
    
    UFUNCTION(BlueprintCallable)
    static void ClearFastTravelTriggerName(EFT_TriggerType TriggerType);
    
};

