#pragma once
#include "CoreMinimal.h"
#include "EInstallFeatures.h"
#include "InstallFeature.generated.h"

USTRUCT(BlueprintType)
struct FInstallFeature {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EInstallFeatures FeatureId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsLanguagePack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString FeatureTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> ChunkIds;
    
    PHOENIX_API FInstallFeature();
};

