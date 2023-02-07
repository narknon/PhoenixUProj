#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "UObject/NoExportTypes.h"
#include "AblAnimationTagChooser_TurnDirection.generated.h"

class UTurnDirectionTagChooser_TargetDirectionGetter;

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_TurnDirection : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector2D> AngleRanges;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTurnDirectionTagChooser_TargetDirectionGetter* TargetDirectionGetter;
    
public:
    UAblAnimationTagChooser_TurnDirection();
};

