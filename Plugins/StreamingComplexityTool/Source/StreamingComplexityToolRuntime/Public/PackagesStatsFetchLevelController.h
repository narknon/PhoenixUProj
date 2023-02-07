#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PackagesStatsFetchLevelController.generated.h"

class UPackageStatsCaptureSettings;
class UWorldStructureDescGenerator;

UCLASS(Blueprintable)
class STREAMINGCOMPLEXITYTOOLRUNTIME_API APackagesStatsFetchLevelController : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPackageStatsCaptureSettings* PackageStatsCaptureSettings;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWorldStructureDescGenerator* WorldStructureGenerator;
    
public:
    APackagesStatsFetchLevelController();
};

