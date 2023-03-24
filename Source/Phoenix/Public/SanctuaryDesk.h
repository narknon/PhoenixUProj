#pragma once
#include "CoreMinimal.h"
#include "TransfigurationObjectBase.h"
#include "SanctuaryDesk.generated.h"

class UCurveFloat;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class ASanctuaryDesk : public ATransfigurationObjectBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* InkWritingMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* InkWritingBackSideMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* InkWritingCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* FrontMaterialInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* BackMaterialInstance;
    
public:
    ASanctuaryDesk(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ClearPage(bool bFrontSide);
    
    UFUNCTION(BlueprintCallable)
    void BeginWritingPage();
    
    UFUNCTION(BlueprintCallable)
    void ApplyMaterialsToPaper(UPrimitiveComponent* InPaperComponent);
    
};

