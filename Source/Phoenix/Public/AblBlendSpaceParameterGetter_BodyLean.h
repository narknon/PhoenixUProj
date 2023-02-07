#pragma once
#include "CoreMinimal.h"
#include "AblBlendSpaceParameterGetter.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "AblBlendSpaceParameterGetter_BodyLean.generated.h"

class AAmbulatory_Character;

UCLASS(Blueprintable, EditInlineNew)
class UAblBlendSpaceParameterGetter_BodyLean : public UAblBlendSpaceParameterGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D SpeedRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D BlendSpaceMaxRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D InterpSpeedRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseSpringInterp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpringHalflife;
    
public:
    UAblBlendSpaceParameterGetter_BodyLean();
protected:
    UFUNCTION(BlueprintCallable)
    void OnTeleport(AAmbulatory_Character* Character, FVector AmountDisplaced, FRotator AmountRotated);
    
};

