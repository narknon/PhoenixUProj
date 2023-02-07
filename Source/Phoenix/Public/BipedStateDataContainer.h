#pragma once
#include "CoreMinimal.h"
#include "BipedStateData.h"
#include "ObjectStateDataContainerBase.h"
#include "BipedStateDataContainer.generated.h"

UCLASS(Blueprintable, NonTransient)
class PHOENIX_API UBipedStateDataContainer : public UObjectStateDataContainerBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBipedStateData Data;
    
    UBipedStateDataContainer();
};

