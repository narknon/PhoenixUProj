#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Components/Image.h"
#include "PhoenixImage.generated.h"

UCLASS(Blueprintable)
class UPhoenixImage : public UImage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataTableRowHandle ColorTag;
    
    UPhoenixImage();
    UFUNCTION(BlueprintCallable)
    void SetColorTag(FDataTableRowHandle NewColorTag);
    
};

