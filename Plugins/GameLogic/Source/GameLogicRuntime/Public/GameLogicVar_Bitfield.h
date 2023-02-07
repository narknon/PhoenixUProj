#pragma once
#include "CoreMinimal.h"
#include "Bitfield256.h"
#include "GameLogicBase.h"
#include "GameLogicVar_Bitfield.generated.h"

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicVar_Bitfield : public UGameLogicBase {
    GENERATED_BODY()
public:
    UGameLogicVar_Bitfield();
    UFUNCTION(BlueprintCallable)
    void SetCachedValue(FBitfield256 Value);
    
    UFUNCTION(BlueprintCallable)
    FBitfield256 GetCachedValue();
    
};

