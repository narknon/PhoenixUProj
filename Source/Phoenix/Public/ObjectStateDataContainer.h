#pragma once
#include "CoreMinimal.h"
#include "ObjectStateData.h"
#include "ObjectStateDataContainerBase.h"
#include "ObjectStateDataContainer.generated.h"

UCLASS(Blueprintable, NonTransient)
class PHOENIX_API UObjectStateDataContainer : public UObjectStateDataContainerBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FObjectStateData Data;
    
    UObjectStateDataContainer();
};

