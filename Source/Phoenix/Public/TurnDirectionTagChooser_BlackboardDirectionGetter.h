#pragma once
#include "CoreMinimal.h"
#include "TurnDirectionTagChooser_TargetDirectionGetter.h"
#include "TurnDirectionTagChooser_BlackboardDirectionGetter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UTurnDirectionTagChooser_BlackboardDirectionGetter : public UTurnDirectionTagChooser_TargetDirectionGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BlackboardKeyName;
    
public:
    UTurnDirectionTagChooser_BlackboardDirectionGetter();
};

