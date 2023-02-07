#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "UObject/NoExportTypes.h"
#include "AblAnimationTagChooser_FootMatch.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_FootMatch : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinTimeIntoMotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeIntoMotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SourceTimeOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector FootPositionWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector FootVelocityWeight;
    
public:
    UAblAnimationTagChooser_FootMatch();
};

