#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser_TurnDirection.h"
#include "TurnDirectionNavMeshCheckSettings.h"
#include "AblAnimationTagChooser_CreatureTurnDirectionWithNavCheck.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_CreatureTurnDirectionWithNavCheck : public UAblAnimationTagChooser_TurnDirection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTurnDirectionNavMeshCheckSettings> NavMeshCheckSettings;
    
    UAblAnimationTagChooser_CreatureTurnDirectionWithNavCheck();
};

