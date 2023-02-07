#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "Components/ActorComponent.h"
#include "EMapRegionType.h"
#include "MapMarkupComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UMapMarkupComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowBannerWhenEntering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMapRegionType> Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo DbId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString RegionName;
    
    UMapMarkupComponent();
    UFUNCTION(BlueprintCallable)
    bool IsStairs();
    
    UFUNCTION(BlueprintCallable)
    bool IsRoom();
    
    UFUNCTION(BlueprintCallable)
    bool IsFloor();
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EMapRegionType> GetType();
    
};

