#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "UObject/NoExportTypes.h"
#include "AblAnimationTagChooser_HandMatch.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_HandMatch : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector HandsPositionWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector HandsVelocityWeight;
    
public:
    UAblAnimationTagChooser_HandMatch();
};

