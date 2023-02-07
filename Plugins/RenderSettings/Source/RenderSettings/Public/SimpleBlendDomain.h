#pragma once
#include "CoreMinimal.h"
#include "SimpleBlendDomain.generated.h"

class URenderSettingsCustomBlendDomain;

USTRUCT(BlueprintType)
struct FSimpleBlendDomain {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URenderSettingsCustomBlendDomain*> Blends;
    
    RENDERSETTINGS_API FSimpleBlendDomain();
};

