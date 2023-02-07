#pragma once
#include "CoreMinimal.h"
#include "AblTaskCondition.h"
#include "AblAmbulatoryGroundDetection.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAmbulatoryGroundDetection : public UAblTaskCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OnGroundDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGroundMustBeWalkable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGroundMustNotBePawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInverse;
    
public:
    UAblAmbulatoryGroundDetection();
};

