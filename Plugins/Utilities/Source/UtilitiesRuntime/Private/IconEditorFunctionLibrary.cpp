#include "IconEditorFunctionLibrary.h"

class UAnimSequence;
class UDataTable;
class USkeleton;
class UTexture2D;
class UTextureRenderTarget2D;

void UIconEditorFunctionLibrary::UpdateIconTableRow(UDataTable* Table, FName RowName, const FIconInfo& IconInfo, bool bSave) {
}

void UIconEditorFunctionLibrary::SaveImageFromRenderTargets(FName Name, UTextureRenderTarget2D* ColorTextureRenderTarget, int32 DownResFactor) {
}

TArray<UAnimSequence*> UIconEditorFunctionLibrary::GetAnimationsForSkeleton(USkeleton* Skeleton) {
    return TArray<UAnimSequence*>();
}

UTexture2D* UIconEditorFunctionLibrary::CreateTextureFromRenderTargets(UTextureRenderTarget2D* ColorTextureRenderTarget, const FString& PackageName, int32 DownResFactor) {
    return NULL;
}

UIconEditorFunctionLibrary::UIconEditorFunctionLibrary() {
}

