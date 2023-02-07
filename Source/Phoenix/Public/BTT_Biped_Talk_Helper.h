#pragma once
#include "CoreMinimal.h"
#include "BlueprintHelper.h"
#include "BTT_Biped_Talk_Helper.generated.h"

class USceneRig;

UCLASS(Blueprintable)
class UBTT_Biped_Talk_Helper : public UBlueprintHelper {
    GENERATED_BODY()
public:
    UBTT_Biped_Talk_Helper();
private:
    UFUNCTION(BlueprintCallable)
    static USceneRig* GetBTTBipedTalkSceneRig();
    
};

