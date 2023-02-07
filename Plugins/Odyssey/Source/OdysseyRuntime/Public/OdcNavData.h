#pragma once
#include "CoreMinimal.h"
#include "NavigationData.h"
#include "OdcNavData.generated.h"

UCLASS(Blueprintable, NotPlaceable)
class ODYSSEYRUNTIME_API AOdcNavData : public ANavigationData {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 Layer;
    
public:
    AOdcNavData();
};

