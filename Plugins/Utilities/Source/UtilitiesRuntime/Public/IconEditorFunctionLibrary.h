#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "IconInfo.h"
#include "IconEditorFunctionLibrary.generated.h"

class UAnimSequence;
class UDataTable;
class USkeleton;
class UTexture2D;
class UTextureRenderTarget2D;

UCLASS(Blueprintable)
class UTILITIESRUNTIME_API UIconEditorFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UIconEditorFunctionLibrary();
    UFUNCTION(BlueprintCallable)
    static void UpdateIconTableRow(UDataTable* Table, FName RowName, const FIconInfo& IconInfo, bool bSave);
    
    UFUNCTION(BlueprintCallable)
    static void SaveImageFromRenderTargets(FName Name, UTextureRenderTarget2D* ColorTextureRenderTarget, int32 DownResFactor);
    
    UFUNCTION(BlueprintCallable)
    static TArray<UAnimSequence*> GetAnimationsForSkeleton(USkeleton* Skeleton);
    
    UFUNCTION(BlueprintCallable)
    static UTexture2D* CreateTextureFromRenderTargets(UTextureRenderTarget2D* ColorTextureRenderTarget, const FString& PackageName, int32 DownResFactor);
    
};

