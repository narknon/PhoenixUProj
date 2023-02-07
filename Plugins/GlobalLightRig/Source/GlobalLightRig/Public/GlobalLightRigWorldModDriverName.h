#pragma once
#include "CoreMinimal.h"
#include "GlobalLightRigWorldModDriverName.generated.h"

USTRUCT(BlueprintType)
struct FGlobalLightRigWorldModDriverName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    GLOBALLIGHTRIG_API FGlobalLightRigWorldModDriverName();
};

