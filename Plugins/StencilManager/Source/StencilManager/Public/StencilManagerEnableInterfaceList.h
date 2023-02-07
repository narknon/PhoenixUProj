#pragma once
#include "CoreMinimal.h"
#include "StencilManagerEnableInterfaceList.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FStencilManagerEnableInterfaceList {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UObject>> Interfaces;
    
    STENCILMANAGER_API FStencilManagerEnableInterfaceList();
};

