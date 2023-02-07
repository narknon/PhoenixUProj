#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AIPerformTaskBase.h"
#include "EPerformTaskHogwarsExpressSettings.h"
#include "AIPerformTaskSpawnHogwartsExpress.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskSpawnHogwartsExpress : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPerformTaskHogwarsExpressSettings CurrentTaskSetting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUpdateLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector NewLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUpdateSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NewSpeed;
    
    UAIPerformTaskSpawnHogwartsExpress();
};

