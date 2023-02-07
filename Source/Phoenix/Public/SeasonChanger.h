#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ESeasonEnum -FallbackName=ESeasonEnum
#include "SeasonChanger.generated.h"

UCLASS(Blueprintable)
class USeasonChanger : public UObject {
    GENERATED_BODY()
public:
    USeasonChanger();
    UFUNCTION(BlueprintCallable)
    static void SetCurrentSeason(ESeasonEnum NewSeason);
    
};

