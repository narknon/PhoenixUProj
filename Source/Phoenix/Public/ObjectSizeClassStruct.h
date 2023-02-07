#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ENoiseSize.h"
#include "Templates/SubclassOf.h"
#include "ObjectSizeClassStruct.generated.h"

class AMunitionType_Base;

USTRUCT(BlueprintType)
struct FObjectSizeClassStruct : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Width;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamagePerSecondMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AMunitionType_Base> OnFireDestroyedAOE;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OnFireDestroyedDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENoiseSize ObjectNoiseSize;
    
    PHOENIX_API FObjectSizeClassStruct();
};

