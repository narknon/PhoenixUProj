#pragma once
#include "CoreMinimal.h"
#include "SpellLevelData.h"
#include "FlipendoLevelData.generated.h"

USTRUCT(BlueprintType)
struct FFlipendoLevelData : public FSpellLevelData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TapBasePhysicsImpulseXY;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TapBasePhysicsImpulseZ;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TapBaseAngularVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TapMassScaledPhysicsImpulseXY;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TapMassScaledPhysicsImpulseZ;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TapMassScaleAngularVelocity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TapMaxVelocity;
    
    PHOENIX_API FFlipendoLevelData();
};

