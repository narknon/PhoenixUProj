#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SocketPreview.h"
#include "WorldEventSocketPreview.generated.h"

UCLASS(Blueprintable)
class UWorldEventSocketPreview : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSocketPreview> WorldPreviewData;
    
    UWorldEventSocketPreview();
};

