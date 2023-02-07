#pragma once
#include "CoreMinimal.h"
#include "IconButtonWidget.h"
#include "MissionLogData.h"
#include "MissionButtonWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UMissionButtonWidget : public UIconButtonWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMissionLogData MissionData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsFocusMission;
    
    UMissionButtonWidget();
};

