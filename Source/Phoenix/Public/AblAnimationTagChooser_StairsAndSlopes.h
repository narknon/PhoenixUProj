#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "EStairsDirectionState.h"
#include "AblAnimationTagChooser_StairsAndSlopes.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_StairsAndSlopes : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EStairsDirectionState::Type> StairsDirection;
    
public:
    UAblAnimationTagChooser_StairsAndSlopes();
};

