#pragma once
#include "CoreMinimal.h"
#include "StencilManagerGroupName.generated.h"

USTRUCT(BlueprintType)
struct FStencilManagerGroupName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    STENCILMANAGER_API FStencilManagerGroupName();
};

