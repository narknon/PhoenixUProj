#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PackageStatsCaptureSettings.generated.h"

UCLASS(Blueprintable)
class STREAMINGCOMPLEXITYTOOLRUNTIME_API UPackageStatsCaptureSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> RawPackages;
    
    UPackageStatsCaptureSettings();
};

