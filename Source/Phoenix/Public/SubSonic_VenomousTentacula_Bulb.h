#pragma once
#include "CoreMinimal.h"
#include "MunitionType_SubsonicSpell.h"
#include "SubSonic_VenomousTentacula_Bulb.generated.h"

UCLASS(Blueprintable)
class ASubSonic_VenomousTentacula_Bulb : public AMunitionType_SubsonicSpell {
    GENERATED_BODY()
public:
    ASubSonic_VenomousTentacula_Bulb(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetupProjectile();
    
};

