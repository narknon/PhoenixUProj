#pragma once
#include "CoreMinimal.h"
#include "MunitionType_SubsonicSpell.h"
#include "MunitionType_Potion.generated.h"

UCLASS(Blueprintable)
class AMunitionType_Potion : public AMunitionType_SubsonicSpell {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpawnDistance;
    
    AMunitionType_Potion();
};

