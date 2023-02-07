#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "DialogueDataTableHandles.h"
#include "FacialComponentShimHelper.generated.h"

UCLASS(Blueprintable)
class UFacialComponentShimHelper : public UObject {
    GENERATED_BODY()
public:
    UFacialComponentShimHelper();
    UFUNCTION(BlueprintCallable)
    static FDialogueDataTableHandles PreloadPlayerMaleFemaleDialogueDataTables();
    
};

