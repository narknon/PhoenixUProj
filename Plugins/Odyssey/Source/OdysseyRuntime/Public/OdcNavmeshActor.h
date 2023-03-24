#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "OdcNavGraphImage.h"
#include "OdcNavmeshActor.generated.h"

UCLASS(Blueprintable, NotPlaceable)
class ODYSSEYRUNTIME_API AOdcNavmeshActor : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FOdcNavGraphImage> NavGraphImages;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector NavmeshExtent;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int8 NavGraphImagesVersion;
    
public:
    AOdcNavmeshActor(const FObjectInitializer& ObjectInitializer);
};

