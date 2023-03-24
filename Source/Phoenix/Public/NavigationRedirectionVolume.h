#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Volume.h"
#include "NavigationRedirectionVolume.generated.h"

UCLASS(Blueprintable)
class ANavigationRedirectionVolume : public AVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector RedirectionLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ForceOverlandArea;
    
    ANavigationRedirectionVolume(const FObjectInitializer& ObjectInitializer);
};

