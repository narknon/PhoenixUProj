#pragma once
#include "CoreMinimal.h"
#include "EPhoenixScalabilityLevel.h"
#include "LumosScalabilitySettingsMatch.generated.h"

class AActor;
class UWorld;

USTRUCT(BlueprintType)
struct FLumosScalabilitySettingsMatch {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorld* World;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Caster;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPhoenixScalabilityLevel PlatformLevel;
    
    PHOENIX_API FLumosScalabilitySettingsMatch();
};

