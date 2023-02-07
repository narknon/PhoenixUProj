#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_Filtered.h"
#include "Templates/SubclassOf.h"
#include "MultiFX2_CameraShake.generated.h"

class UCameraShakeBase;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_CameraShake : public UMultiFX2_Filtered {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraShakeBase> CameraShake;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InnerRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OuterRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Falloff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOrientShakeTowardsEpicenter;
    
public:
    UMultiFX2_CameraShake();
};

