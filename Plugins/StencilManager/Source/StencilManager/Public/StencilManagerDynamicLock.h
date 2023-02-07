#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "StencilManagerDynamicLock.generated.h"

class AStencilManagerSingleton;

UCLASS(Blueprintable, Transient)
class STENCILMANAGER_API UStencilManagerDynamicLock : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AStencilManagerSingleton> StencilManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Priority;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 LastUsedStencilValue;
    
    UStencilManagerDynamicLock();
};

