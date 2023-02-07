#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AIPerformTaskContainer.generated.h"

class UAIPerformTaskBase;

USTRUCT(BlueprintType)
struct FAIPerformTaskContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAIPerformTaskBase* TaskData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform WidgetTransform;
    
    PHOENIX_API FAIPerformTaskContainer();
};

